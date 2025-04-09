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
//aa*a+
//s2,s4,r3,s5,s9,
//FOLLOW(S)   $
//FOLLOW(B)   +, *, $
//FOLLOW(A)	  a, +, *, $
//		a	+	*	$	S	A	B
//0		s2			    1
//1					acc			
//2	    s4 r2						3
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
//
//S -> AaAb | BbBa
//A -> e
//B -> e
//
//LL(1)
//S ->  AaAb -> aAb -> ab
//S -> BbBa -> bBa -> ba
//		a				b
//S		S ->AaAb	S -> BbBa
//A		A -> e		 A -> e
//B		B -> e		 B -> e
//
//SLR(1)
//l0: S' -> .S, S -> .AaAb, S -> .BbBa, A -> e, B -> e
//l1: (l0:S) S' -> S. 
//l2: (l0:A) S -> A.aAb
//l3: (l0:B) S -> B.bBa
//l4: (l2:a)
//
//S -> SA | A
//A -> a
//
//S -> AB
//B -> AB | e
//A -> a
//
//S -> A1b1
//S -> A2b2
//
//A1 -> a2A1
//A1 -> a2
//
//A2 -> a1A2
//A2 -> a1
//
//l0: .S
//l1: S.
//l2: (l0:A1)
//l3: (l0:A2)
//l4: (l0:a1) a1.A2, a1., A2...
//l5: (l0:a2) a2.A1, A2., A1...
//l6: (l2:b1)
//l7: (l3:b2)
//l8: (l4:A2)
//l9: (l5:A1)

//		a			$
//S		S -> AB
//B		B -> AB		B -> e
//A     A -> a
//
//
//a1: A2A3A4 -> a2A3,a2A4 || a3A4, a2A4 || a4A2, a4A3
//a3: A1A2A4 -> a2A1 || a1A2
//a2: A1A3A4 -> a3A1 || a1A3
//a4: A1A2A3 ->
//2n + 2 + 2^n - 2 + n*(n - 1)
//
//2n + n^2 + 2^n
//
//2n + 2 + n + n^2 - 2 = 3n + n^2
//S -> Aibi           n + n,     	(读入A1,A2,A3,...,An, 共n个状态)
//
//Ai -> ajAi          n + n * (n - 1) (先读入aj, j = 1~n, 共n个状态，后续读入Ai, i = 1 ~ n且 i != j, 所以后续会产生n * (n - 1))
//
//Ai -> aj			  n   (因Ai -> ajAi, 在读入aj后可进行递归, aj.Ai, .ajAi, .aj)
//					  
// aj.Ai aj.
// 2n^ - n        	n^2 - n
//
//A3 -> a2A3
//A3 -> a1A3
//a1A3
//a1A2
//a1
//a2.A1   A1 -> a2A1            A1 -> .a2A1 =a2=>  (A1 -> a2.A1),  A1 -> .a2A1, A1 -> .a2
//a2.A2
//a2.An
//a2.
//...
//
//n = 2
//S -> A1b1
//S -> A2b2
//
//A1 -> a2A1
//A1 -> a2
//
//A2 -> a1A2
//A2 -> a1
//
//a1 -> 2^(n - 1) * n
//
//2n + n(n - 1) + (2^(n - 1) - 1) * n                       
//2n + n^2 - n + 2
//
//n^2 + n + 2 + (2^(n - 1) - 1) * n
//
//n^2 + 2  + n*2(n - 1)  
//
//l0: S ->....
//l1: S
//l1: (l0:A1) S -> A1.b1
//l2: (l0:A2) S -> A2.b2
//
//l3: (l0:a1) A2 -> a1.A2, 
//l4: (l0:a2) A1 -> a2.A1
//
//l5: (l3:A2) A2 -> a1A2.               a1A2,a1A3,   a1A2,  a1A3
//l6: (l4:A1) A1 -> a2A1.
//
//l7: (l1:b1) S -> A1b1.
//l8: (l2:b2) S -> A2b2.
//
//
//A3 -> a1A3      A3-> a1.A3	A1...A3   1234     1234   123 124 134 234	12 13 14 23 24 34 1 2 3 4
//A3 -> a2A3	  A2-> a1.A2
//				  A4 ->a1.A4 
//
//aj.Ai, (Ai => 2)   Ai -> .a
//ajAi.
//
//l1(l0:Ai) Ai.bi					
//
//l2(l0:aj) aj.Ai, aj. , .ajAi, .aj   						              
//
//l3(l1:bi) Aibi.                   n2
//
//l4(l1:aj) aj.Ai, .ajAi, .aj, aj.
//l5(l2:Ai) ajAi.					n(n + 1)
//l6(l2:aj) aj.Ai  .ajAi .aj  aj.
//
//1 + n^2 + n^2 - n
//						aj.Ai, Ai => 2     |		ajAi.
//n(n - 1)  n^2 -n					   
//
//
//n = 3
//
//S -> A1b1
//S -> A2b2
//S -> A3b3
//
//A1 -> a2A1
//A1 -> a3A1
//A1 -> a2
//A1 -> a3
//
//A2 -> a1A2
//A2 -> a3A2
//A2 -> a1
//A2 -> a3
//
//A3 -> a1A3
//A3 -> a2A3
//A3 -> a1
//A3 -> a2
//
//a1A2, a1A3, ...a1An                         
//a2A1, a2A3, ...a2An
//anA1, anA2, ...anAn-1
//
//ai[Aj], j != i......				aj..
//
//
//
//l0: S -> ....
//l1: (l0:S) S' -> S.
//2n + 2 + n + n(n - 1) +  n(n - 1)..1                  A2,A3,A4 =a2=> A3, A4 || =a3=> A2,A4 || A2,A3
//
//l2: (l0:A1) S -> A1.b1							    A3,A4 =a1=> a1.A3, a1.A4
//l3: (l0:A2) S -> A2.b2								A3,A4 =a3=> a3.A4,
//l4: (l0:A3) S -> A3.b3								A3,A4 =a4=> a4,A3
//
//l5: (l0:a1) A2->a1.A2 A2 ->a1. A3->a1.A3 A3 -> a1.			A2, A3 =a2=> a2.A3, a2. A3... ||  A2, A3 =a3=> a3.A2, a3. A2...
//l6: (l0:a2) ...												A1, A3 =a1=> a1.A3, a1. A3... ||  A1, A3 =a3=> a3.A1, a3. A1...
//l7: (l0:a3) ...												A1, A2 =a1=> a1.A2, a1. A2... ||  A1, A2 =a2=> a2.A1, a2. A1...
//
//l8: (l2:b1)
//l9: (l3:b2)
//l10: (l4:b3)
//
//l11: (l5:A2) A2 -> a1A2.
//l12: (l5:A3) A3 -> a1A3.
//
//l13
//l14
//
//l5
//l16
//
//l17: (l5: a1) A
//
//S -> SS+ | SS* | a
//
//l0: S' -> .S ...
//l1: (l0:S) S' -> S., S.S+, S.S*,  .SS+, .SS*
//l2: (l0:a) a.
//l3: (l1:S) SS.+, SS.*, S.S*, S.S+, .SS+, .SS*   (l3:S) -> l3
//l4: (l3:+) SS+.
//l5: (l3:*) SS*.
//
//           S =S=> SS
//
//S -> AS | b
//A -> SA | a
//
//S' -> S		  1
//S -> AS         2
//S -> b          3
//A -> aB		  4
//B -> SAB	 	  5 
//B -> e		  6
//FOLLOW(S)	a, $
//FOLLOW(A) a, b, $
//FOLLOW(B) a, b, $
//
//l0 S' -> .S, S -> .AS, S -> .b, A -> .aB
//l1 (l0:S) S' -> S.
//l2 (l0:A) S -> A.S,  S -> .AS, S -> .b    A -> .aB     | =A=> l2,  =a=> l3
//l3 (l0:a) A -> a.B,  B -> .SAB, B -> .,  S -> .AS, S -> .b, A -> .aB      |   =A=> l2, =b=> l5
//l4 (l2:S) S -> AS.
//l5 (l2:b) S -> b.
//l6 (l3:B) A -> aB.
//l7 (l3:S) B -> S.AB, A -> .aB | =a=> l3
//l8 (l7:A) B -> SA.B, B -> .SAB, B -> ., S -> .AS, S -> .b, A -> .aB | =S=> l7, =A=> l2, =b=> l5
//l9 (l8:B) B -> SAB.
//
//		a		b	$	 A	 B	 S
//l0	S3		s5		 g2		 g1
//l1	r1			acc	 		 
//l2	s3      s5		 g2      g4  
//l3    s3/r6   s5/r6 r6 g2  g6  g7
//l4    r2          r2	  
//l5    r3      r3  r3				
//l6	r4		r4  r4		
//l7    s3               g8
//l8    s3/r6   s5/r6 r6  g2 g9  g7
//l9	r5     r5   r5
