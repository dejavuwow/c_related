//E -> E t1 E | E t2 E | E tn E | (E) | id
//
//E' -> .E
//E -> .E t1 E | .... | .E tn E | .(E) | .id
//
//E -> E.t1 E | ... | E.tnE
//
//E -> (.E)  E closure
//
//E -> id.	
//
//E -> (E.) 
//
//E -> (E).
//
//E -> Et1.E    .Et1...tn
//
//E -> Et1E.  E.t1....E.tn
//
//E1 -> E1 tn E2 | E2
//E2 -> E2 tn-1 E3 | E3
//...
//En -> En t1 En+1 | En+1
//En+1 -> (E1) | id
//E1' -> .E1    .E1tnE2   .E2    .E2tn - 1E3   .E3 .... .En    .Ent1En+1      .En+1		.(E1)   .id
//E1.
//E2.
//..
//En-1.t2En
//En-1t2.En     .Ent1En+1	
//En-1t2En. En.t1En+1
//En+ 1.
//
//
//Ent1.En+1,  .(E1),   .id
//
//Ent1En+1.
//
//4n +
//
//E2tn-1E3.   E3.tn-2E4
//
