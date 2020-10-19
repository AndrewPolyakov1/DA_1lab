#include "sort.hpp"
#include <iostream>

namespace NSort {

    NMytypes::TPair<int,  char[65]>& max_elem(const NVector::TVector<NMytypes::TPair<int, char[65]>>& vector) {
        NMytypes::TPair<int, char[65]> tmp = vector[0];
        NMytypes::TPair<int,  char[65]> &res = tmp;
        int max = -1;
        for (size_t i = 0; i < (vector.size()); ++i) {
            if (vector[i].key >= max) {
                max = vector[i].key;
                res = vector[i];
            }
        }
        return res;
    }

    void counting_sort(NVector::TVector<NMytypes::TPair<int,  char[65]>>& elems)
    {
        if (elems.is_empty()) {
            return;
        }

        NMytypes::TPair<int,  char[65]> max_element_pair = max_elem(elems);
        //max_element_pair.print_pair();
        unsigned max_elem = max_element_pair.key;

        NVector::TVector<unsigned int> account(max_elem + 1, 0);

        //Accounting number of each key
        for (size_t i = 0; i < elems.size(); ++i) {
            
            account[elems[i].key]++;
            //printf("%d\n", elems[i].key);
        }



        for (size_t i = 1; i < account.size(); ++i) {
            //if (account[i] > 0) printf("%d %d\n", i, account[i]);
            account[i] += account[i - 1];
        }

        NVector::TVector<NMytypes::TPair<int,  char[65]>> result(elems.size());

        for (int i = elems.size() - 1; i >= 0; --i) {
            /*auto key = elems[i].key;
            auto pos = account[key]--;
            result[pos - 1] = elems[i];*/

            result[account[elems[i].key] - 1] = elems[i];
            --account[elems[i].key];
        }

        //std::swap(result, elems);
        for (size_t i = 0; i < elems.size(); ++i) {
            std::swap(result[i], elems[i]);
            //elems[i] = result[i];
        }
    }
}