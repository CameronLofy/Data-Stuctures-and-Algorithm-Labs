#include "doubly_linked_list.h"

namespace lab6{
    // Auxiliary Functions
    unsigned partition(int* to_sort, int low, int high);

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort);
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right);

    void quicksort(int* to_sort, int low, int high){

    }

    unsigned partititon(int* to_sort, int low, int high){

    }

    void mergesort(doubly_linked_list& to_sort){
        recursive_merge_sort(to_sort);
    }

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort){
        if(to_sort.size() == 1){
            return to_sort;
        }
        unsigned mid = to_sort.size()/2;
        doubly_linked_list half2 = to_sort.split(mid);
        recursive_merge_sort(to_sort);
        recursive_merge_sort(half2);
        return merge(to_sort, half2);
    }

    //Used for the merging the two lists
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right){
        doubly_linked_list merged;
        int i, k =0;
        while(i<left.size() && k<right.size()){
            if(left.get_data(i) < right.get_data(k)){
                merged.append(left.get_data(i));
                i++;
            }
            if(left.get_data(i) > right.get_data(k)){
                merged.append(right.get_data(k));
                k++;
            }
            if(left.get_data(i) == right.get_data(k)){
                merged.append(left.get_data(i));
                merged.append(right.get_data(k));
                i++;
                k++;
            }
        }
        return merged;

    }
}