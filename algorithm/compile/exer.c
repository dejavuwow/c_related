void S() {
	if (lookhead == '0'):
		match('0'); S(); match("1");
}
}
void scan() {
	int peek;
	if (peek == '/' && peek[1] == '/') {
		while (System.in.read() == '\n') break;
	}

	if (peek == '/' && peek[1] == '*') {
		while (System.in.read() == '*')
	}
	if ("." == peek || isDigit(peek)) {
		pre = peek;
		peek = read();
		if (isDigit(pre)) {
			if (peek == '.') {
				while (isDigit(read()))
			}
		} else if ('.' == peek && isDigit(read())) {

		}
	}
}

class For extends Stmt {
	Expr e1, e2, e3;
	Stmt s;
	public For(Expr r1, Expr r2, Expr r3, Stmt s1) {
		e1 = r1;
		e2 = r2;
		e3 = r3;
		s = s1;
		loop = newlabel();
		after = newlabel();
	}
	public void gen() {
		e1.gen();
		emit(loop + ":");
		e2n = e2.rvalue();
		emit("ifFalse"+ e2n.toString()+ "goto" + after);
		s.gen();
		e3.gen();
		emit("goto" + loop);
		emit(after + ":");
	}
}
"abce", "abcdef"
//maxlength[i]: i下标结尾的字符串的最长子序列长度
//headmost[i]: i下标结尾的字符串最长子序列在另外一个字符串中的匹配的字符串最后一个字符的下标(匹配到的字符串中，该字符串的最后一个字符下标最小)
//str1[i] == str2[k], 且 k > headmost[i - 1], maxlength[i] = maxlength[i - 1] + 1
//
int longestCommonSubsequence(char* text1, char* text2) {

	int l1 = strlen(text1),
		l2 = strlen(text2);
	int maxlength[l];
	int headmost[l];
	int count = 1;

	memset(maxlength, 0, sizeof(maxlength));
	memset(headmost, l2, sizeof(headmost));

	int find = 0;
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++) {
			if (text1[i] == text2[j]) {
				maxlength[i] = 1;
				headmost[count] = j; 
				find = 1;
				break;
			}
		}
		if (find) break;
	}


	for (int i = 0; i < l1; i++) {
		int find = 0;
		for (int j = headmost[count]; j < l2; j++) {
			if (text1[i] == text2[j]) {
				maxlength[i]++;
				headmost[++count] = j; 
				find = 1;
				break;
			}
		}
		if (!find) {
			int countIndex = count;
			while (countIndex > 0) {
				for (int j = headmost[countIndex - 1] + 1; j < headmost[countIndex]; j++) {
					if (text1[i] == text2[j]) {
						headmost[countIndex] = j; 
						break;
					}
				}
				countIndex--;
			}
		}
	}

	return maxlength[l1 - 1];
}


int longestCommonSubsequence(char* text1, char* text2) {
    int m = strlen(text1), n = strlen(text2);
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; i++) {
        char c1 = text1[i - 1];
		int pre = 0;
        for (int j = 1; j <= n; j++) {

            char c2 = text2[j - 1];
			int newLen = pre;
			pre = dp[j];

            if (c1 == c2) {
                dp[j] = pre + 1;
            } else {
				d[j] = fmax(d[j], d[j - 1]);
            }
        }
    }
    return dp[n];
}
//[a-zA-Z]
//abcdef
//a ab abc abcd abcde abcdef
	b  bc bcd bcde bcdef				  
// (s|S)(e|E)()
// /a[a-z]*eiou/
// /a*b*c*/
// /*
// ("*/")*
// */  r -> [0-9]
//(ab+a*)+ab+    ab+a+b(a*b)*
//
//(ab+a*)(ab+a*)*ab+
//(ab+a*)ab+
//(ab+a*)(ab+a*)+ab+
//ab
//S -> SS+ | SS* | a   aa+a*
//
//S -> SS*
//SS* -> SS+ S*
//SS+S* -> aS+S* -> aa+S* -> aa+a*
//
//
//S -> SS*
//SS* ->Sa* -> SS+a* -> Sa+a* -> aa+a*
//
//         S
//      /  | \
//     S   S  *
//    /|\  |
//   S S + a
//   | |
//   a a
//
//  S -> 0 S 1 | 01   000111
//  S -> 0S1 -> 00S11 -> 0001111
//              S
//           0  S   1
//             0S1
//              01
// S -> + SS | * SS | a,  +*aaa
// S -> + SS -> + *SSS -> + *aSS-> +*aaS -> +*aaa;
// S -> + SS -> + Sa -> + *SSa -> + *Saa -> +*aaa;
// 
//
//             S
//          +  S  S
//
//S -> S(S)S | e, (()())
//S -> S(S)S -> e(S)S -> e(S(S)S)S -> e(e(S)S)S -> e(e(e)S)S -> e(e(e)S(S)S)S -> e(e(e)e(S)S)S -> e(e(e)e(e)S)S -> e(e(e)e(e)e)e
//
//S -> S+S | SS | (S) | S* | a, (a+aa)*a
//S -> SS -> S*S -> (S)*S -> (S+S)*S -> (a+S)*S -> (a+SS)*S -> (a+aS)*S -> (a+aa)*S -> (a+aa)*a
//S -> SS -> S*S -> (S)*S -> (SS)*S -> (S+SS)
//S -> SS -> S + S S -> a + a  a
//S -> S + S -> S + SS -> a + a a
//
//S -> (L) | a
//L -> L, S | S, ((a, a), a, (a))
//
//S -> (L) -> (L, S) -> (S, S) -> ((L), S) -> ((L, S), S) -> ((S, S), S) -> ((a, a), L, S) -> ((a, a), S, S)
//((a, a), S, S) -> ((a, a), a, (L)) -> ((a, a), a, (S)) -> ((a, a), a, (a))
//
//S -> a S b S | b S a S | e,  aabb ab          aSb S -> a aS b S  b S ->  a aSb bSaS bS 
//S -> aSbS -> a aSbS SbS -> aaebeebaSbS ->
//S -> aSbS ->
//
//bexpr -> bexpr or bterm | bterm
//bterm -> bterm and bfactor | bfactor
//bfactor -> not bfactor | ( bexpr ) | true | false
//
//bexpr -> bterm A
//A -> or bterm A | e
//
//bterm -> bfactor B
//B -> and bfactor B | e
// 
//bfator -> not bfactor | (bexpr)
//
//S -> 1S | 0A
//
//S -> 0 S 0 | 1 S 1 | 0 | 1 | e
//
//S -> 0 S 1 S | 1 S 0 S | e
//01 01
//S -> 0 | 1 | 00 | 01 | 10 | 11                         0 # 1 1,  1 -> ~, 0 0 
//
//S -> B | 1A
//B -> A | 1
//A -> 0S | 0
//
//S -> xA
//A -> yzA | e
//
//stmt -> if expr then stmt [else stmt]
//begin stmtList end
//stmtList -> stmt[;stmtList]
//S -> Aa
//A -> SbB
//B -> A3
//A -> AabB
//A
//rexpr->rexpr + rterm |  rterm
//rterm -> rterm rfactor | rfactor
//rfactor -> rfactor * | rprimary
//rprimary -> a | b
//
//rexpr -> rterm A
//A -> + term A | e
//
//rterm -> rfactor B
//B -> rfactor B | e
//
//rfactor -> rprimary C
//C -> * C | e
//
//S -> SS+  | SS* | a
//
//S -> SSA | a
//A -> + | *
//
//S -> aB
//B -> SAB | e
//B -> aBAB | e
//
//S -> 0S1 | 01
//
//S -> 0A
//A -> S1 | 1
//A -> 0A1 | 1
//
//S ->  S(S)S | e
//S -> A
//A -> (S)SA | e
//
//S -> (L) | a
//L -> L, S | S
//
//L -> L, (L) | a  |  (L) | a
//
//L -> (L)A | a A 
//A -> , (L) | a A | e
//
//S -> i E t S | M
//M -> i E t M e S | O 
//
//S -> i E t S -> i E t M -> i E t . i E t M e S -> i E t . i E t M e . i E t M e S
//S -> M -> i E t M e S -> i E t . i E t M e . i E t M  . e S ->  
//
//S -> ABCD
//
//eNum = 0;
//for (i = k; k = ABCD.length; k++) {
//	FIRST(S).add(FIRST(i))(exclude e);
//	if (i ! => e) break;
//	eNum++;
//}
//if (eNum == ABCD.length) FIRST.add(e);
//
//
//FOLLOW, S
//1、S 为产生式头部，则添加$
//2、S在产生式体中的后面跟着一个文法符号A,则添加FIRST(A)
//3、A -SB | S在产生式体的末尾或者后面跟着FIRST(B)包含e, 那么
//FOLLOW(S)一定包含所有的FOLLOW(A)
//
//预测分析表
//M[S, a]
//S -> A放入到M中，如果FIRST(A)包含a
//S -> A, FIRST(A)包含e, FOLLOW(S)中的每个b, M[S, b]都包含 S -> A($结束符号也包含在内)

//CNF形式文法转化
//1,消除e产生式
//2,消除单一非终结符产生式
//3, 转换终结符，将包含终结符的2个和2个以上的产生式体 转换为只包含非终结符
//4, 拆分长度为3个和3个以上的产生式体，如 A -> BCD 拆分成 A -> BE, E -> CD
//
//A -> BC | d
//B -> EA | f
//E -> c
//C -> g
//
//A -> EAC | fC | d
//A -> cAg | fg | d
//
//CYK算法
//S -> AB 存在于  X[i][j]
//存在一个k, i <= k < j
//A -> CD 存在于X[i][k] 且 B -> EF 存在于X[k+1][j]
//###
// ###
// 	##
// 	 ##
// 	  ##
// 	   ##
// 	   CNF L(V,T,P,S), input: w (a1a2..an)
// 	   dp[n + 1][n + 1];
// 	   for (int i = 1; i < n + 1; i++) {
// 	   		if (A -> wi in P) {
// 	   			add A to dp[i][i]
// 	   		}
// 	   }
// 	   for (int l = 2; l < n + 1; l++) {			i + l - 1 = n
// 	   	  for (int i = 1; i <= n - l + 1; i++) {
// 	   	  	for (int k = i; k < i + l - 1; k++) {
// 	   	  		if (A -> BC in P && B in dp[i][k] && C in dp[k+1][j]) {
// 	   	  			add A to dp[i][j];
// 	   	  		}
// 	   	  	}
// 	   	  }
// 	   }
// 	   if (S in dp[1][n]) return yes
// 	   else return no
//
//
//编辑距离
// 	   CNF L(V,T,P,S), input: w (a1a2..an)
// 	   dp[m][n + 1][n + 1] n: str.length, m: nums of V
// 	   
// 	   init dp table(for single character)
//
//		for i in 1 to n
//			for each production A -> a in P	
//				a =*> s  #s为生成的最短字符串
//				l = s.length
//				dp[A][i][i] = min(dp[A][i][i], s contains w[i] ? l - 1 : l)
//
//		for l in 2 to n				
//			for i in 1 to n - l + 1
//				j = i + l - 1
//				for k in i to j - 1
//					for each production A -> BC in P
//						dp[A][i][j] = min(dp[A][i][j], dp[B][i][k] + dp[C][k + 1][j])
//
//				
//				
//A -> BC
//dp[A][i][k] dp[B][k + 1][j]
//
//A -> BC
//B -> DE
//C -> FG
//D -> a
//E -> b
//F -> MN
//M -> c
//N -> d
//G -> e
//
//ab cde          abde           
//a bcde
//
//B -> a   C -> cde
//dp[B][i][k]
//
