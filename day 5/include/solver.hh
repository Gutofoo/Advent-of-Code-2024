#ifndef _SOLVER_HH_
#define _SOLVER_HH_

#include <algorithm>
#include <utility>
#include <vector>

#include "types.hh"

template<parts p>
class Solver {

    public:
        Solver(const RulesAndUpdates& parsedInput) :
            data_(parsedInput) { }
        int solve();

    private:
        const RulesAndUpdates& data_;

        struct UpdatesMetadata {
            bool is_valid = false;
            int center_page_value = 0;
        };

        std::vector<rule> ExtractRelevantRules(const update& current_update);

        bool CheckUpdateValidity(const update& current_update, const std::vector<rule>& relevant_rules);

};

template<parts p>
std::vector<rule> Solver<p>::ExtractRelevantRules(const update& current_update) {

    std::vector<rule> relevant_rules;

    for(int i = 0; i < data_.rules.size(); i++) {

        const rule& current_rule = data_.rules[i];

        if(std::any_of(current_update.begin(), current_update.end(), [current_rule](page current_page){ return current_page == current_rule.first; })
          && std::any_of(current_update.begin(), current_update.end(), [current_rule](page current_page){ return current_page == current_rule.second; })) {
            relevant_rules.push_back(current_rule);
        }

    }


    return relevant_rules;

}

template<parts p>
bool Solver<p>::CheckUpdateValidity(const update& current_update, const std::vector<rule>& relevant_rules) {

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
                    return false;
                }
            }
        }

        printed_pages.push_back(current_page);

    }

    return true;

}

#endif