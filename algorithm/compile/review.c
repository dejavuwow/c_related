//A -> Aa | Ab | y
//A -> AC | y
//C -> a | b
//
//A -> yB
//B -> CB | e
//高效计算LALR(1)项集族算法(本质是合并具有相同内核项的项集, 规约冲突会延迟报错, 即按照错误的向前看符号进行规约，会在下次移入符号时报错)
//1、计算LR(0)内核项
//2、计算内核项I在文法符号X上产生的GOTO(I, X)的自发生成的向前看符号
//核心逻辑：
//for each A in I
//	J = CLOSURE([A -> a.b, #])
//	if ([B -> y.Xz, c] IN J AND c != #)
//		GOTO(I, X)中的项[B -> yx.z, c]向前看符号为自发生成
//	if ([B -> y.Xz, #] IN J)
//		I中的项 A-> a.b 的向前看符号传播到GOTO(I, x)中的项 B -> yX.z上
//
//
//完整步骤：
//queue.add([S -> .S, $])
//while(A = queue.shift())
//	J = CLOSURE([A -> a.b, #])
//	for each INPUT X
//		if ()
//		if ([B -> y.Xz, c] in J AND c != #)
//			queue.add([B -> yX.z, c])
//
//		
