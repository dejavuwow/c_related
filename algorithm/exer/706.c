//(let x 2 (mult x (let x 3 y 4 (add x y))))
struct my_struct {
	char name[11];             /* key (string is WITHIN the structure) */
	int val;
	UT_hash_handle hh;         /* makes this structure hashable */
};

enum keyword {
	LET,
	ADD,
	MULT
};
enum type {
	VAR,
	LITERAL,
	EXPRESSION,
	INIT
};
struct token {
	enum type type;
	char name[11];
	int val;
};
#define CASE_LET(str, idx) (strncmp(str + idx, "let ", 4) == 0)
#define CASE_ADD(str, idx) (strncmp(str + idx, "add ", 4) == 0)
#define CASE_MULT(str, idx) (strncmp(str + idx, "mult ", 5) == 0)
#define COPY_SCOPE(dest, src) {\
	if (src != NULL) {\
		HASH_ITER(hh, src, var, temp) {\
			cr = malloc(sizeof(struct my_struct));\
			strcpy(cr->name, var->name);\
			cr->val = var->val;\
			HASH_ADD_STR(dest, name, cr);\
		}\
	}\
}
int idx = 0;
int length;
void getToken(char *dest, char *str) {
	int i = 0;
	while (str[idx] != ' ' && str[idx] != ')') {
		dest[i++] = str[idx++];
	}
	dest[i] = '\0';
}

int getVal(char *str) {
	int num = 0;
	int sign = 1;
	if (str[idx] == '-') {
		sign = -1;
		idx++;
	}
	while (str[idx] != ' ' && str[idx] != ')') {
		num = num * 10 + str[idx++] - 0x30;
	}
	return num * sign;
}
int parse(char *str, struct my_struct *pScope) {

	struct my_struct *scope = NULL, *var, *temp, *cr;
	struct token cur, pre;
	pre.type = INIT;
	COPY_SCOPE(scope, pScope);
	enum keyword keyToken = CASE_LET(str, idx) ? LET : CASE_ADD(str, idx) ? ADD : CASE_MULT(str, idx);
	idx += 4;
	for (; idx < length && str[idx] != ')';) {
		if (str[idx] == ' ') {
			idx++;
			continue;
		}
		else if (str[idx] == '(') {
			idx++;
			cur.val = parse(str, scope);
			cur.type = EXPRESSION;
		}
		else {
			if (str[idx] >= 0x61 && str[idx] <= 0x7a) {
				cur.type = VAR;
				getToken(cur.name, str);
				HASH_FIND_STR(scope, cur.name, var);
				if (var) {
					cur.val = var->val;
				}
			}
			else {
				cur.type = LITERAL;
				cur.val =  getVal(str);
			}
		}
		if (keyToken == LET && pre.type == VAR) {
			HASH_FIND_STR(scope, pre.name, var);
			if (!var) {
				var = malloc(sizeof(struct my_struct));
				strcpy(var->name, pre.name);
				HASH_ADD_STR(scope, name, var);
			}      
			var->val = cur.val;
		}
		else if (pre.type != INIT) {
			if (keyToken == ADD) {
				cur.val += pre.val;
			}
			else if (keyToken == MULT) {
				cur.val *= pre.val;
			}
		}
		pre = cur;
	}
	idx++;
	return cur.val;
}
int evaluate(char * expression){
	struct my_struct *scope = NULL;
	idx = 1;
	length = strlen(expression);
	return parse(expression, scope);
}
