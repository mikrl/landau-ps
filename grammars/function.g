/*
* Parser Rules
*/

function	: function  ;
division	: \frac{function}{function} ;
operation	: ('+' | '-' | '/' | '*' | '^') ;


/*
* Lexer Rules
*/

fragment LOWERCASE  : [a-z] ;
fragment UPPERCASE  : [A-Z] ;
fragment WORD		: (LOWERCASE+ | UPPERCASE+) ;
fragment DIGIT		: [0-9] ;
NUMBER				: DIGIT+ ([.,] DIGIT+)? ;
TERM				: (NUMBER | WORD | WORD '_' DIGIT+) ;
    

