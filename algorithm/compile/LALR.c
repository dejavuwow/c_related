//有效项形如[A -> a.Bb, a]
//规范LR
//构造LR(1)项集族算法 
//除了理想化的自我在他人身上的投射，除了想像孩子一样被怜惜照顾以外，我们爱过别人吗
I CLOSURE(I) {
	repeat
		for (each [A -> a.Bb, a] in I) 
			for (each [B -> y]) 
				for (each d in FIRST(ba))
					put [B -> .y, d] in I;
	until no new item put in;
	return I;
}

I GOTO(I, X) {
	J //init empty
	for (each [A -> a.Xb, a] in I)
		put [A -> aX.b, a] in J;

	return CLOSURE(J);
}

void item(G') { //构造项集族
	C //初始化为CLOSURE([S -> .S, $])
	repeat
		for (each I in C) 
			for (each INPUT X)  //X为文法符号
				if (GOTO(I, X) not empty and not in C) 
					put GOTO(I, X) in C;
	until no new item  put in
}
//S -> SS+
//S -> SS*
//S -> a
//
//l0: (S' -> .S, $),  [S -> .SS+, $],  [S -> .SS*, $],  [S -> .a, $],  [S -> .SS+, a], [S -> .SS*, a], [S -> .a, a]
//l1: (l0: S) (S' -> S. $) (S -> S.S+, $/a) (S -> S.S*, $ / a) [S -> .SS+, + / *] [S -> .SS*, + /*] [S -> .a, + / *]
//l2: (l0: a) (S ->a., $) (S -> a., a)
//l3: (l1: S) (S -> SS.+, $ / a) (S -> SS.*, $ / a) (S -> S.S+, + / *) (S -> S.S*,  + / *) [S -> .SS+, +/*] [S -> .SS*, + / *]
//l4: (l1: a) (S -> a., + / *) 
//l5: (l3: *) (S -> SS*., $)
//l6: (l3: +) (S -> SS+., $)
//
//l7: (l3: S) (S -> SS.+, +/*) (S -> SS.*, +/*) (S -> S.S+, + /*) (S -> S.S*, + / *)
//			   [S -> .SS+, +/*] [S -> .SS*, +/*] [S -> .a, +/*]
//
//l8: (l7: +) (S -> SS+., +/*)
//l9: (l7: *) (S -> SS*., +/*)
//(l7: S) l7
//(l7: a) l4
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//l0: (S' -> .S, $),  (S -> .aB, $)
//l1: (l0: S) (S' -> S. ,$)
//l2: (l0: a) (S -> a.B, $), [B -> .SAB, $], [B -> e, $], [S -> .aB, + / *]
//l3: (l2: B) (S -> aB., $)
//l4: (l2: S) (B -> S.AB, $) [A -> .+, e/a] [A -> .*, e/a]
//l5: (l2: a) (S -> a.B, +/*) [B -> .SAB, + / *] [S -> .aB, +/*]
//l6: (l4: A) (B -> SA.B, $) [B -> .SAB, $] [B -> e, $]
//l7: (l4: +) (A -> +., e / a)
//l8: (l4: *) (A -> *., e/a)
//l9: (l5: B) (S -> aB. +/*)
//l10: (l5: S) (B -> S.AB, +/*) [A -> .+, a / e], [A -> .*, a /e]
//(l5: a) l5
//l11 : (l6: B) (B -> SAB. $)
//(l6: S) l4
//l12: (l10: A) (B ->SA.B, +/*) [B -> .SAB, + / *] [B -> e, + / *]
//l13: (l10: +) (A -> +., a / e)
//l14: (l10: *) (A -> *., a / e)
//l15: (l12: B) (B -> SAB., + / *)
//(l12: S) l10
