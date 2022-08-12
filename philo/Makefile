NAME = philo

SRC = philosophers.c

GCC = cc


all : $(NAME)

$(NAME) : $(SRC)
	@gcc $(SRC) -Wall -Werror -Wextra -g -fsanitize=address -o $(NAME)
	@echo "\033[1;32m Philo is ready !"



clean :
		@rm -f $(NAME)
		@echo "\033[1;32m File cleaned !"

fclean : 
		@rm -f $(NAME)
		@echo "\033[1;32m File cleaned !"

re : fclean all

push :
		git add .
		git commit -m "philo"
		git push
		@echo "\033[1;32m File pushed !"