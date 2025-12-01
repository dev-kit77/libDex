#ifndef DEF_H
#define DEF_H

//Loan Related Constants
#define CURRENT_TIME std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())
#define LOAN_DURATION (30*60*60*24)
#define BOOK_RATE 0.000025 //fraction of penny to be added per overdue second = £2.16 per day

//OK codes
#define OK 200
#define ELEMENT_ADDED 201
#define ELEMENT_UPDATED 202
#define ELEMENT_DELETED 203
#define ELEMENT_FOUND 204
#define FILE_WRITTEN 205

//Error codes
#define GENERAL_ERROR 400
#define CANNOT_ADD 401
#define CANNOT_UPDATE 402
#define CANNOT_DELETE 403
#define ELEMENT_NOT_FOUND 404
#define FILE_NOT_FOUND 405
#define ELEMENT_ALREADY_EXISTS 406

#endif
