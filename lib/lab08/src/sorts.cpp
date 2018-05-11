#include "doubly_linked_list.h"

namespace lab6{
    // Auxiliary Functions
    unsigned partition(int* to_sort, int low, int high);
    void swap(int to_sort[], int a, int b);

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort);
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right);

    void quicksort(int* to_sort, int low, int high){
        unsigned part;
        if(high - low <2){
            return;
        }
        part = partition(to_sort, low, high);
        quicksort(to_sort, low, part-1);
        quicksort(to_sort, part+1, high);

    }

    unsigned partition(int* to_sort, int low, int high){
        int pivot = to_sort[high];
        int i = low-1;
        for(int j = low; j<=high-1; j++){
            if(to_sort[j] < pivot){
                i++;
                swap(to_sort,i,j);
            }
        }
        i++;
        swap(to_sort,i,high);
        return i;
    }

    void swap(int *to_sort, int a, int b){
        int temp = to_sort[a];
        to_sort[a] = to_sort[b];
        to_sort[b] = temp;
    }

    void mergesort(doubly_linked_list& to_sort){
        to_sort = recursive_merge_sort(to_sort);
    }

    doubly_linked_list recursive_merge_sort(doubly_linked_list to_sort){
        if(to_sort.size() == 1){
            return to_sort;
        }
        unsigned mid = to_sort.size()/2;
        doubly_linked_list half2 = to_sort.split(mid);
        to_sort = recursive_merge_sort(to_sort);
        half2 = recursive_merge_sort(half2);
        to_sort = merge(to_sort, half2);
        return to_sort;
    }

    //Used for the merging the two lists
    doubly_linked_list merge(doubly_linked_list left, doubly_linked_list right){
        doubly_linked_list merged;
        unsigned i=0;
        unsigned k=0;
        while(i!=left.size() && k!=right.size()) {
            if (left.get_data(i) < right.get_data(k)) {
                merged.append(left.get_data(i));
                i++;
            } else if (left.get_data(i) > right.get_data(k)) {
                merged.append(right.get_data(k));
                k++;
            } else if (left.get_data(i) == right.get_data(k)) {
                merged.append(left.get_data(i));
                merged.append(right.get_data(k));
                i++;
                k++;
            }
        }
        if (i == left.size()) {
            while(k != right.size()) {
                merged.append(right.get_data(k));
                k++;
            }
            return merged;
        }
        if (k == right.size()) {
            while(i != left.size()) {
                merged.append(left.get_data(i));
                i++;
            }
            return merged;
        }
        return merged;

    }
}