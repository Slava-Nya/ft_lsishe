//
// Created by youpaw on 11.03.2020.
//

#ifndef NODES_H
#define NODES_H
# include "srcs.h"

struct					s_node
{
	char				path[MAX_PATHLEN];
	char				*error;
	struct stat			info;
	t_avl 				*srcs;
};

typedef struct s_node	t_node;

t_node	*get_error_node(char *path);
/*
 * Функция принимает на вход переданный в аргументы и проверенный в get_node невалидный путь
 * В переменной errno хранится код ошибки который привел к вызову функции
 *
 * Функция создает новую ноду, в поле path записывает принятый аргумент, в поле error
 * записывает сгенерированную строку выводимой ошибки
 * Примеры строк ошибок смотри в баш ^_^
 * Строка ошибки генерируется вручную исходя из кода ошибки с помощью функции nstrjoin
 * (есть еще стандартные функции чтобы получить строку ошибки из кода эррно, надо прочекать подойдет ли нам,
 * создам на тебя таску прочекать этот момент)
 *
 * В остальные поля записывается null
 *
 * Функция возвращает созданную ноду
 */

t_node 	*get_file_node(char *argv, struct stat info, t_flags *flags);
t_node	*get_dir_node(char *argv, struct stat info, t_flags *flags);
t_node	*get_node(char *argv, t_flags *flags);
void	del_node(t_node **node);
/*
 * Функция принимает аргумент переданный из parse_args и структуру флагов
 *
 * Функция берет stat файла или папки c помощью стандартной функции stat
 * В случае ошибки функция вызывает get_error_node и возвращает полученное из нее значения
 *
 * Если переданный аргумент является путем на папку, то функция вызывает с этим аргументом функцию opendir
 * В случае ошибки функция вызывает get_error_node и возвращает полученное из нее значения
 * В случае успешного выполнения opendir функция вызывает get_srcs и полученное значение заносит в поле srcs
 *
 * Если переданный аргумент является путем на файл, то в поле srcs заносится значение null
 *
 * В поле path заносится принятый аргумент,
 * В поле info заносится полученное значение из stat
 * В поле next заносится значение null
 *
 * Функция возвращает созданную ноду
 */
int		cmp_nodes(t_node *node1, t_node *node2, t_flags *flags);
/*
 * принимает на вход добавляемую ноду в список, текущую проверяемую ноду из списка и струкутуру
 * флагов
 *
 * Функция проверяет поле error добавляемой ноды, если он не null, то функция сразу возвращает -1
 * Если оно null а поле error не null, то функция возвращает сразу 1
 * Если оба поля не null, то функция возврощает 1
 *
 * Функция берет флаг из поля sort структуры флагов и исходя из значений поля сравнивает
 * соответсвтующие поля принятых нод, если поля идентичные и сортировка производится не по имени,
 * то функция должна сравнить их по имени с помощью функции ft_strcmp
 *
 * Если поля сравниваются по имени, то функция должна сравнить их поля path с помощью функции ft_strcmp
 *
 * Функция проверяет наличие флага 'r' и инвертирует возвращаемое значение в случае наличия флага
 * Функция возвращает разницу между сравниваемыми значениями, пример ft_strcmp
 *
 */


#endif //NODES_H
