NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror

SRCS = check_arguments.c \
       data_init.c \
       philo.c \
       utils.c \
	   philo_actions.c

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) $(OBJS)

re: fclean all
