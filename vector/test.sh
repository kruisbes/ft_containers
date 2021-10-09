#!/bin/zsh
if [ 'bzz' = "$1" ]
then
	if grep "ft::vector" ./main.cpp > /dev/null
	then
		sed -i '' " s/ft::vector/std::vector/g" ./main.cpp
		echo "\033[38;5;224;1mft has been successfully replaced with std\033[0m"
	else
		sed -i '' "s/std::vector/ft::vector/g" ./main.cpp
		echo "\033[38;5;224;1mstd has been successfully replaced with ft\033[0m"
	fi
	return
fi

clear
if grep "ft::vector" ./main.cpp > /dev/null
then
	clang++ -Wall -Wextra -Werror main.cpp -o ft_vector -Ofast
	time ./ft_vector > ft_output
	sed -i '' "s/ft::vector/std::vector/g" ./main.cpp
	clang++ -Wall -Wextra -Werror main.cpp -o std_vector -Ofast
	time ./std_vector > std_output
	sed -i '' "s/std::vector/ft::vector/g" ./main.cpp
else
	clang++ -Wall -Wextra -Werror main.cpp -o std_vector -Ofast
	time ./std_vector > std_output
	sed -i '' "s/std::vector/ft::vector/g" ./main.cpp
	clang++ -Wall -Wextra -Werror main.cpp -o ft_vector -Ofast
	time ./ft_vector > ft_output
	sed -i '' "s/ft::vector/std::vector/g" ./main.cpp
fi

if diff -E ft_output std_output
then
	echo "\033[32mDiff 0 OK!\033[0m"
	#rm std_output
	#rm ft_output
else
	echo "\033[31mDiff != 0 ERROR\033[0m"
fi
rm -rf std_vector
rm -rf ft_vector
if [ 'clear' = "$1" ]
then
	rm -rf ft_output
	rm -rf std_output
	rm -rf a.out
	rm -rf ft_vector
	rm -rf std_vector
	rm -rf a.out.dSYM
	rm -rf vector.dSYM
	echo "\033[38;5;412mDelete output files\033[0m"
fi
