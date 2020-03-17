//
// Created by youpaw on 12.03.2020.
//

#ifndef LS_H
#define LS_H
#include "flags.h"
#include "list_lib.h"

void	print_args(t_list **nodes, t_flags *flags);

t_list *parse_args(int argc, char **argv, int skip, t_flags *flags);
/*
 * Функция получается на вход:
 * количество аргументов argc
 * аргументы argv
 * количество распарсенных аргументов skip
 * распарсенные флаги flags
 *
 * Для каждого argv функция создает соответствующую ноду с помощью функции создания нод get_node
 * и добавляет ее в общий список нод с помощью функции ft_lstaddsort которая принимает на вход
 * адрес текущего списка нод, новую ноду для добавления, структуру флагов, и адрес
 * сортировочной функции cmp_nodes описанной в nodes.h
 *
 * Функция возвращает сгенерированный, сортированный список нод типа t_list
 */

#endif //LS_H