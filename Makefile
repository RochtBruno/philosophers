NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = philo.c \
		check_arguments.c \
		data_init.c \
		eat.c \
		philo_dead.c \
		sleep.c \
		time.c \
		utils.c \
		start_dinner.c \

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
