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

        const bool update_is_valid = CheckUpdateValidity(current_update, relevant_rules);

        // successful update: write the metadata
        if(update_is_valid) {
            metadata[i].is_valid = true;
            center_idx = current_update.size()/2; // intentional truncation using integer division
            metadata[i].center_page_value = current_update[center_idx];

            // update the sum
            sum += metadata[i].center_page_value;
        }

    }

    return sum;

}

template<>
int Solver<parts::PART2>::solve() {

    return 0;

}