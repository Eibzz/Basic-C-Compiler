#ifndef __STATEMACHINE_H__
#define __STATEMACHINE_H__

#include "token.h"

enum MachineState {
	START_STATE, IDENTIFIER_STATE, INTEGER_STATE, CANTMOVE_STATE,
	LPAREN_STATE, RPAREN_STATE, LCURLY_STATE, RCURLY_STATE, LESS_STATE,
	LESSEQUAL_STATE, INSERTION_STATE, GREATER_STATE, GREATEREQUAL_STATE, HO_STATE, HA_STATE, OR_STATE, AND_STATE, NOT_STATE,
	EQUAL_STATE, ASSIGNMENT_STATE,
	PLUS_STATE, MINUS_STATE, TIMES_STATE, DIVIDE_STATE, LINECOMMENT_STATE, BLOCKCOM1_STATE, BLOCKCOM2_STATE, BLOCKCOM3_STATE,
	SEMICOLON_STATE, ENDFILE_STATE, 
	LAST_STATE
	};

enum CharacterType {
	LETTER_CHAR, DIGIT_CHAR, WHITESPACE_CHAR, BAD_CHAR,
	LPAREN_CHAR, RPAREN_CHAR, LCURLY_CHAR, RCURLY_CHAR, LESS_CHAR, GREATER_CHAR, EQUAL_CHAR, OR_CHAR, AND_CHAR, NOT_CHAR,
	UNDERSCORE_CHAR, PLUS_CHAR, MINUS_CHAR, TIMES_CHAR, DIVIDE_CHAR,
	SEMICOLON_CHAR, NEWLINE_CHAR, ENDFILE_CHAR,
	LAST_CHAR
	};

class StateMachineClass
{
public:
	StateMachineClass();
	MachineState UpdateState(char currentCharacter, TokenType &correspondingTokenType);

private:
	MachineState mCurrentState;

	MachineState mLegalMoves[LAST_STATE][LAST_CHAR];

	// Which end-machine-states correspond to which token types.
	// (non end states correspond to the BAD_TOKEN token type)
	TokenType mCorrespondingTokenTypes[LAST_STATE];
};


#endif