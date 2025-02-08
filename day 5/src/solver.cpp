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

        size_t center_idx = 0; // pre-declaration to permit goto later

        // let's extract the relevant rules for this update
        std::vector<rule> relevant_rules = ExtractRelevantRules(current_update);

        // track printed pages while assessing the current page in the requested update
        std::vector<page> printed_pages;
        for(size_t j = 0; j < current_update.size(); j++) {

            // extract the next requested page in the update
            const page& current_page = current_update[j];

            // go through the relevant rules
            for(const rule current_rule : relevant_rules) {

                // if this page appears in the second part of a rule, must check that all prerequisites are met
                if(current_page == current_rule.second) {
                    if(std::none_of(printed_pages.begin(), printed_pages.end(), [current_rule](const page& printed_page){ return printed_page == current_rule.first; })) {
                        // failed check: prerequisite has not been met!
                        // skip to next update
                        goto SKIP_TO_NEXT_UPDATE;
                    }
                }
            }

            printed_pages.push_back(current_page);

        }

        // successful update: write the metadata
        metadata[i].is_valid = true;
        center_idx = current_update.size()/2; // intentional truncation using integer division
        metadata[i].center_page_value = current_update[center_idx];

        // update the sum
        sum += metadata[i].center_page_value;

        SKIP_TO_NEXT_UPDATE:;

    }

    return sum;

}

template<>
int Solver<parts::PART2>::solve() {

    return 0;

}