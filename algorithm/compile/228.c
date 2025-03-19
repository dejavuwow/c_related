//S -> 0S1 | 01
//
//S -> 0A
//A -> S1 | 1
//			0		1
//S		S -> 0A
//A		A -> S1		 A -> 1
//
//S -> ++S | *SS | a
//		+ *  a
//  
//S -> S + S | SS | (S) | S* | a
//S -> SA | (S) | a
//A -> +S | S | *
//
//S -> TB
//B -> AB | e
//A -> +S | S | *
//T -> (S) | a
//
//		+  		(   		)		*			a
//S		     S -> TB                        S->TB
//B	 B->AB	 B->AB					B->AB     B->AB
//A  A->+S   A->S					A->*      A->S
//T          T->(S)                           T->a
//
////S -> S + S | SS | (S) | S* | a
//
//S -> (L) | a
//L -> SA
//A -> ,SA | e
//
//		(			)			a			,			$
//S  S->(L)         		S->a
//L  L->SA					L->SA
//A										A->,SA		A->e
//
//
// S -> aSbS | bSaS | e 
//			a		b		$
//S						  S->e
//
//
//bexpr -> bexpr or bterm | bterm
//bterm -> bterm and bfactor | bfactor
//bfactor -> not bfactor | ( bexpr ) | true | false
//
//
//bexpr -> bterm A
//A ->    or bterm A | e
//bterm -> bfactor B
//B -> and bfactor B | e
//bfactor -> not bfactor | ( bexpr ) | true | false
//
//
//	  		and		or		not		(		)		true	false
//bexpr	                   
//FOLLOW(B)
//FOLLOW(bterm) = or && FOLLOW(bexpr) = )
//
//S -> SS+ | SS * | a
//S -> SSA | a
//
//S -> aB
//B -> SAB | e
//A -> + | *
//
//S -> aSa | aa
// 					
//S -> aSa  	 aa aa aa
//     Sa        a aa aa
//    aSaa		 a aa aa
//    Saa		 aa aa
//    aSaaa      aa aa
//    Saaa       aaa
//    aSaaaa	 aaa
//    Saaaa		 aa
//    
//S -> aSbS | bSaS | e
//S -> aSbS | abS | aSb | ab | bSaS | baS | bSa | ba
//
//
//E -> E + T | T 		        
//T -> T * F | F
//F -> (E) | id
//
//(E,E) (E,T) (T,T)(T,F)(F,F)
//
//E -> E + T | T * F | (E) | id
//T -> T * F | (E) | id
//F -> (E) | id
//
//S -> A | a
//A -> B | b
//B -> S | c
//
//S -> B | b | a
//S ->
//
//  aabd
//  abd
//
//stmt -> if e then stmt stmtTail
//		| while e do stmt
//		| begin list end
//		| s
//
//stmtTail  -> else stmt
//			 | e
//
//list -> stmt listTail
//listTail -> ;list
//			| e
//
//				if				  ;				else                  $                while            begin
//stmt		 stmt -> if ..
//stmtTail	 					stmtTail ->e	stmtTail ->e		stmtTail -> e
//list		 list -> stmt                                                              list -> stmt     list->stmt
//listTail                      listTail -> ;list                   listTail -> e
//

