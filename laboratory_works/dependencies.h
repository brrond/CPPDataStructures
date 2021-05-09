#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cmath>

#define MODE 0
// 0 - DEBUG
// 1 - End after first start
// 2 - work until exit command

//#include "../slist_llist_cllist/list.h"
#include "../slist_llist_cllist/linked_list.h"
//#include "../slist_llist_cllist/circular_linked_list.h"

#include "../stack_queue_deque/stack.h"
#include "../stack_queue_deque/queue.h"
#include "../stack_queue_deque/deque.h"

#include "../binary_trees/binary_tree.h"
#include "../binary_trees/red_black_tree.h"

#include "../algorithms/sorts.h"

#include "../algorithms/search.h"
#include "../algorithms/substr.h"

#include "../hash/chain_hash.h"

int main_lab1();

int main_lab2_stack();
int main_lab2_queue();
int main_lab2_deque();

int main_lab3_binary_search_tree();
int main_lab3_red_black_tree();

int main_lab4();

int main_lab5_search();
int main_lab5_substr();

int main_lab6();