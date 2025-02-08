#include <algorithm>
#include <array>
#include <utility>
#include <vector>

#include "solver.hh"
#include "types.hh"

template<>
int Solver<parts::PART1>::solve() {

    std::vector<UpdatesMetadata> metadata = std::vector<UpdatesMetadata>(data_.updates.size());

    int sum = 0;

    // gotta loop over the updates!
    for(size_t i = 0; i < data_.updates.size(); i++) {

        const update& current_update = data_.updates[i];

        // let's extract the relevant rules for this update
        std::vector<rule> relevant_rules = ExtractRelevantRules(current_update);

        const bool update_is_valid = CheckUpdateValidity(current_update, relevant_rules);

        // successful update: write the metadata
        if(update_is_valid) {
            metadata[i].is_valid = true;
            const size_t center_idx = current_update.size()/2; // intentional truncation using integer division
            metadata[i].center_page_value = current_update[center_idx];

            // update the sum
            sum += metadata[i].center_page_value;
        }

    }

    return sum;

}

template<>
int Solver<parts::PART2>::solve() {

    int sum = 0;

    // gotta loop over the updates!
    for(size_t i = 0; i < data_.updates.size(); i++) {

        const update& current_update = data_.updates[i];

        // let's extract the relevant rules for this update
        std::vector<rule> relevant_rules = ExtractRelevantRules(current_update);

        const bool update_is_valid = CheckUpdateValidity(current_update, relevant_rules);

        // invalid update - time to reorder it!
        if(!update_is_valid) {

            update unpublished = current_update;
            std::vector<page> published;

            while(!unpublished.empty()) {

                for(update::iterator j = unpublished.begin(); j != unpublished.end(); j++) {

                    const page& current_page = *j;

                    std::vector<page> prerequisites;

                    // find the prerequisites relevant to the current page
                    for(size_t k = 0; k < relevant_rules.size(); k++) {
                        if(relevant_rules[k].second == current_page) {
                            prerequisites.push_back(relevant_rules[k].first);
                        }
                    }

                    bool prerequisites_met = true;

                    // now loop through the prerequisites to ensure each is met in the set of published pages
                    for(size_t k = 0; k < prerequisites.size(); k++) {
                        const page& current_prerequisite = prerequisites[k];
                        if(std::any_of(published.begin(), published.end(), [current_prerequisite](page input){ return input == current_prerequisite; })
                          || prerequisites.empty()) {
                            continue;
                        } else {
                            prerequisites_met = false;
                            break;
                        }
                    }

                    // all prerequisites met on the page in question: publish it, remove from the temp update
                    if(prerequisites_met) {
                        published.push_back(current_page);
                        unpublished.erase(j);
                        break;
                    }

                }

            }

            // by this point, the erroneous update has been corrected
            const size_t center_idx = published.size()/2; // intentional integer division
            sum += published[center_idx];

        }

    }

    return sum;


}