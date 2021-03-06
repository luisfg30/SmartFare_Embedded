/*
 * SmartFareData.h
 *
 *  Created on: 2016
 *      Author: Luis Fernando Guerreiro
 *      		Diego Gabriel Lee
 */

#ifndef INC_SMARTFAREDATA_H_
#define INC_SMARTFAREDATA_H_

#define USER_BUFFER_SIZE 10
#define MIN_BALANCE 300
#define VEHICLE_ID 18456

/*****************************************************************************
 * Public types/enumerations/variables
 ****************************************************************************/


// Structure used to store user Data
typedef struct {
	unsigned int userId; // the PICC used stores a 4 byte user ID
	unsigned int vehicleId;
	unsigned int fare;
	int balance;  // the user balance in cents, may be negative
	unsigned int distance; // last travel fare calculated
	unsigned int
		inOdometerMeasure; // vehicle odometer read when user get on board
	RTC_TIME_T inTimestamp;
	float inLatitude;				 // Latitude when user get on board
	float inLongitude;				 // Longitude when user get on board
	unsigned int outOdometerMeasure; // vehicle odometer read when user get out
									 // of the vehicle
	RTC_TIME_T outTimestamp;
	float outLatitude;  // Latitude when user get out of the vehicle
	float outLongitude; // Longitude when user get out of the vehicle
} UserInfo_T;

// Used to show proper massages in the LCD displays
typedef enum __UserStatus {

	START_MESSAGE,
	USTATUS_UNAUTHORIZED,  // user is already on board
	USTATUS_INSUF_BALANCE, // user have insufficient balance
	USTATUS_AUTHORIZED,	// user have enough balance
	USTATUS_TAP_OUT,	   // user get out of the vehicle, new_balance >
						   // minimum_balance
	USTATUS_TAP_OUT_LOW_BALANCE
} UserStatus;

#endif /* INC_SMARTFAREDATA_H_ */
