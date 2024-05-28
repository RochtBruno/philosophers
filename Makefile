NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS =  Parse/check_arguments.c \
        Parse/error.c \
        main.c \
        Routine/philo.c \
        Routine/watcher.c \
        Utils/philo_utils.c \
        Utils/utils.c \
        Philo_actions/forks.c \
        Philo_actions/eat.c \
        Philo_actions/sleep.c \
        Philo_actions/think.c

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