#!/bin/zsh
if [ 'clear' = "$1" ]
then
	rm -rf ft_output
	rm -rf std_output
	rm -rf a.out
	rm -rf ft_set
	rm -rf std_set
	rm -rf a.out.dSYM
	rm -rf set.dSYM
	echo "\033[38;5;412mDelete output files\033[0m"
	return
fi

if [ 'bzz' = "$1" ]
then
	if grep "ft::set" ./main.cpp > /dev/null
	then
	  sed -i '' "s/ft::pair/std::pair/g" ./main.cpp
		sed -i '' "s/ft::set/std::set/g" ./main.cpp
		echo "\033[38;5;224;1mft has been successfully replaced with std\033[0m"
	else
	  sed -i '' "s/std::pair/ft::pair/g" ./main.cpp
		sed -i '' "s/std::set/ft::set/g" ./main.cpp
		echo "\033[38;5;224;1mstd has been successfully replaced with ft\033[0m"
	fi
	return
fi

clear
if grep "ft::set" ./main.cpp > /dev/null
then
	clang++ -Wall -Wextra -Werror main.cpp -o ft_set -Ofast
	time ./ft_set > ft_output
	sed -i '' "s/ft::pair/std::pair/g" ./main.cpp
	sed -i '' "s/ft::set/std::set/g" ./main.cpp
	clang++ -Wall -Wextra -Werror main.cpp -o std_set -Ofast
	time ./std_set > std_output
	sed -i '' "s/std::pair/ft::pair/g" ./main.cpp
	sed -i '' "s/std::set/ft::set/g" ./main.cpp
else
	clang++ -Wall -Wextra -Werror main.cpp -o std_set -Ofast
	time ./std_set > std_output
	sed -i '' "s/pair::set/ft::pair/g" ./main.cpp
	sed -i '' "s/std::set/ft::set/g" ./main.cpp
	clang++ -Wall -Wextra -Werror main.cpp -o ft_set -Ofast
	time ./ft_set > ft_output
	sed -i '' "s/ft::pair/std::pair/g" ./main.cpp
	sed -i '' "s/ft::set/std::set/g" ./main.cpp
fi

if diff -E ft_output std_output
then
	echo "\033[32mDiff 0 OK!\033[0m"
	#rm std_output
	#rm ft_output
else
	echo "\033[31mDiff != 0 ERROR\033[0m"
fi
rm -rf std_set
rm -rf ft_set

