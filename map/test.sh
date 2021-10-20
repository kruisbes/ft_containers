#!/bin/zsh
if [ 'c' = "$1" ]
then
	if grep "ft::pair" ./main.cpp > /dev/null
	then
		sed -i '' "s/ft::pair/std::pair/g" ./main.cpp
		echo "\033[38;5;224;1mft has been successfully replaced with std\033[0m"
	else
		sed -i '' "s/std::pair/ft::pair/g" ./main.cpp
		echo "\033[38;5;224;1mstd has been successfully replaced with ft\033[0m"
	fi
	return
fi

if [ 'clean' = "$1" ]
then
	rm -rf std_rb_tree
	rm -rf ft_rb_tree
	rm -rf ft_output
	rm -rf std_output
	rm -rf a.out
	rm -rf a.out.dSYM
	rm -rf rb_tree.dSYM
	rm -rf redBlackTree
	rm -rf redBlackTree.dSYM
	echo "\033[38;5;412mDelete output files\033[0m"
	return
fi

clear
#if grep "ft::pair" ./main.cpp > /dev/null
#then
#	clang++ -Wall -Wextra -Werror -I../utils/ -Iiterators main.cpp -o ft_rb_tree -Ofast
#	time ./ft_rb_tree > ft_output
#	sed -i '' "s/ft::pair/std::pair/g" ./main.cpp
#	sed -i '' "s/ft::make_pair/std::make_pair/g" ./main.cpp
#	clang++ -Wall -Wextra -Werror  -I../utils/ -Iiterators main.cpp -o std_rb_tree -Ofast
#	time ./std_rb_tree > std_output
#	sed -i '' "s/std::pair/ft::pair/g" ./main.cpp
#	sed -i '' "s/std::make_pair/ft::make_pair/g" ./main.cpp
#else
#	clang++ -Wall -Wextra -Werror -I../utils/ -Iiterators main.cpp -o std_rb_tree -Ofast
#	time ./std_rb_tree > std_output
#	sed -i '' "s/std::pair/ft::pair/g" ./main.cpp
#	sed -i '' "s/std::make_pair/ft::make_pair/g" ./main.cpp
#	clang++ -Wall -Wextra -Werror -I../utils/ -Iiterators main.cpp -o ft_rb_tree -Ofast
#	time ./ft_rb_tree > ft_output
#	sed -i '' "s/ft::pair/std::pair/g" ./main.cpp
#	sed -i '' "s/ft::make_pair/std::make_pair/g" ./main.cpp
#fi
#if diff -E ft_output std_output
#then
#	echo "\033[32mDiff 0 OK!\033[0m"
#	#rm std_output
#	#rm ft_output
#else
#	echo "\033[31mDiff != 0 ERROR\033[0m"
#fi