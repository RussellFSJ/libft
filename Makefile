CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC_DIR = src
OBJ_DIR = obj
FT_PRINTF_DIR = ft_printf
GET_NXT_LN_DIR = get_next_line

SRC_FILES = 	ft_atoi.c  ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
				ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
				ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
				ft_tolower.c ft_toupper.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c 

SRC_FILES_BONUS = 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
					ft_lstsize_bonus.c ft_lstlast_bonus.c \
					ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
					ft_lstclear_bonus.c ft_lstiter_bonus.c \
					ft_lstmap_bonus.c

FT_PRINTF_FILES =	dictionary.c ft_printf.c handle_char.c handle_int.c \
                  	handle_lowerhex.c handle_percent.c handle_ptr.c \
                  	handle_str.c handle_uint.c handle_upperhex.c print_hex.c

GET_NXT_LN_FILES =	get_next_line.c

SRC_FILES := $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES))
SRC_FILES_BONUS := $(patsubst %, $(SRC_DIR)/%, $(SRC_FILES_BONUS))
FT_PRINTF_FILES := $(patsubst %, $(SRC_DIR)/$(FT_PRINTF_DIR)/%, $(FT_PRINTF_FILES))
GET_NXT_LN_FILES := $(patsubst %, $(SRC_DIR)/$(GET_NXT_LN_DIR)/%, $(GET_NXT_LN_FILES))

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
OBJ_FILES_BONUS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES_BONUS))
FT_PRINTF_OBJ_FILES = $(patsubst $(SRC_DIR)/$(FT_PRINTF_DIR)/%.c, $(OBJ_DIR)/$(FT_PRINTF_DIR)/%.o, $(FT_PRINTF_FILES))
GET_NXT_LN_OBJ_FILES = $(patsubst $(SRC_DIR)/$(GET_NXT_LN_DIR)/%.c, $(OBJ_DIR)/$(GET_NXT_LN_DIR)/%.o, $(GET_NXT_LN_FILES))

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ_FILES) $(OBJ_FILES_BONUS) $(FT_PRINTF_OBJ_FILES) $(GET_NXT_LN_OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES) $(OBJ_FILES_BONUS) $(FT_PRINTF_OBJ_FILES) $(GET_NXT_LN_OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(FT_PRINTF_DIR)/%.o: $(SRC_DIR)/$(FT_PRINTF_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(GET_NXT_LN_DIR)/%.o: $(SRC_DIR)/$(GET_NXT_LN_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re