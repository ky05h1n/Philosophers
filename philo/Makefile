NAME = philo

SRC = philo_args.c \
	  philo_utils.c \
	  philo_main.c \
	  philo_threadinit.c \


GCC = cc


all : $(NAME)

$(NAME) : $(SRC)
	@gcc $(SRC) -Wall -Werror -Wextra -pthread -g -fsanitize=address -o $(NAME)
	@echo "\033[1;32m Philo is ready !"



clean :
		@rm -f $(NAME)
		@echo "\033[1;32m File cleaned !"

fclean : 
		@rm -f $(NAME)
		@echo "\033[1;32m File cleaned !"

re : fclean all

push :
		@rm -f $(NAME)
		@rm -rf philo.dSYM
		git add .
		git status
		git commit -m "philo"
		git push
		@echo "\033[1;32m File pushed !"