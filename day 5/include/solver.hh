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

#endif