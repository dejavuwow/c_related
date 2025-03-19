//
//S -> 0 S 1 | 0 1
//S -> 0A
//A -> 0A1 | 1
//
//ava prefix: 0, 01, 0S, 0S1,
//000111 : 0001 => 00S1 => 0S1
//0001     11
//00S	   11
//00S1		1
//0S		1
//0S1		
//S
//
//00S11
//S -> SS+ | SS* | a
//
//S -> SSA | a
//
//S' -> S
//S -> aB
//B -> aBAB | e
//A -> + | *
//
//FOLLOW(S)   $
//FOLLOW(B)   +, *, $
//FOLLOW(A)	  a, +, *, $
//		a	+	*	$	S	A	B
//0		s2			    1
//1					acc			
//2	    s4						3
//3		            r
//4
//5
//6
//7
//8
//9
//
//l0: .S, .aB
//l1: (l0:S) S.
//l2: (l0:a) a.B, .aBAB, .
//l3: (l2:B) aB.
//l4: (l2:a) a.BAB, .aBAB, .
//l5: (l4:B) aB.AB, .+, .*,
//l6: (l4:a) l4
//l7: (l5:A) aBA.B .aBAB, .
//l8: (l5:+) +.,
//l9: (l5:*) *.,
//l10: (l7:B) aBAB.
//l11: (l7:a) l4
//
//prefix: a, aa+, aa+(\+|\-)
//SSS+a*+
//SSS+a*a+
//aaa*a++
//
//S ->SS+ -> SSS*+ -> SSa*+ -> SSS+a*+
//SS a*+
//
//T -> FA
//F -> ab
//A -> cd
//
//Aab
//S -> S(S)S | e
//
//S' -> S
//S -> A
//A -> (S)SA | e
//
//l0:  .S, .A, .(S)SA, .
//l1: (l0: S) S.
//l2: (l0: A) A.
//l3: (l0: () (.
