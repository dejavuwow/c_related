//有效项形如[A -> a.Bb, a]
//规范LR
//构造LR(1)项集族算法 
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

void item(G') {
	C //初始化为CLOSURE([S -> .S, $])
	repeat
		for (each I in C) 
			for (each INPUT X)  //X为文法符号
				if (GOTO(I, X) not empty and not in C) 
					put GOTO(I, X) in C;
	until no new item  put in
}
//LALR
//aBCba
//aBDa
//D.a
