//S' -> S
//S -> L=R
//S -> R
//L -> *R
//L -> id
//R -> L
//
//I0: S' -> .S,  S -> .L=R, S -> .R, L -> .*R, L -> .id, R -> .L
//I1: (I0: S) S' -> S.
//I2: (I0: L) S -> L.=R, R -> L.
//I3: (I0: R) S -> R.
//I4: (I0: *) L -> *.R, R -> .L
//I5: (I0: id) L -> id.
//I6: (I2: =) S -> L=.R, R -> .L
//I7: (I4: R) L -> *R.
//I8: (I4: L) R -> L.
//I9: (I6: R) S -> L=R.
//
//S -> Aa
//S -> bAc
//S -> dc
//S -> bda
//A -> d
//
//I0: S' -> .S, S -> .Aa, S -> .bAc, S -> .dc, S -> .bda, A -> .d
//I1: (I0: S) S' -> S.
//I2: (I0: A) S -> A.a
//I3: (I0: b) S -> b.Ac, S -> b.da, A -> .d
//I4: (I0: d) S -> d.c, A -> d.
//I5: (I2: a) S -> Aa.
//I6: (I3: A) S -> bA.c
//I7: (I3: d) S -> bd.a, A -> d.
//I8: (I4: c) S -> dc.
//I9: (I6: c) S -> bAc.
//I10: (I7: a) S -> bda.
//				init		1           2		3
//S -> .S		 $			$			$		$
//S -> S.					$			$       $
//S -> A.a		 a			$/a			$/a     $/a
//S -> b.Ac					$			$       $
//S -> d.c					$			$       $
//S -> b.da					$			$       $
//A -> d.		 c			$/c			$/c     $/c
//S -> Aa.					a			$/a     $/a
//S -> bA.c								$		$
//S -> bd.a								$		$
//S -> dc.								$		$
//S -> bAC.										$
//S -> bda.										$
