NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS =	check_arguments.c \
		error.c \
		main.c \
		forks.c \
		philo_utils.c \
		philo.c \
		utils.c \
		eat.c \
		sleep.c \
		think.c \
		watcher.c


OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(OBJS)

re: fclean all