-- Keep a log of any SQL queries you execute as you solve the mystery.

.tables

.schema crime_scene_reports

SELECT description
  FROM crime_scene_reports
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND street = 'Humphrey Street';

/*
Accurate description:
    Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
    Interviews were conducted today with three witnesses who were present at the time –
    each of their interview transcripts mentions the bakery.
*/

.schema interviews

SELECT name, transcript
  FROM interviews
 WHERE day = 28
   AND month = 7
   AND year = 2021;

/*
Accurate interviews:
    Name: Ruth
    Transcript: Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
    If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

    Name: Eugene
    Transcript: I don't know the thief's name, but it was someone I recognized.
    Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

    Name: Raymond
    Transcript: As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
    In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
    The thief then asked the person on the other end of the phone to purchase the flight ticket.
*/

.schema bakery_security_logs

SELECT hour, minute, activity, license_plate
  FROM bakery_security_logs
 WHERE hour = 10
   AND day = 28
   AND month = 7
   AND year = 2021;

/*
Possible suspects:
    | hour | minute | activity | license_plate |
    | 10   | 16     | exit     | 5P2BI95       |
    | 10   | 18     | exit     | 94KL13X       |
    | 10   | 18     | exit     | 6P58WS2       |
    | 10   | 19     | exit     | 4328GD8       |
    | 10   | 20     | exit     | G412CB7       |
    | 10   | 21     | exit     | L93JTIZ       |
    | 10   | 23     | exit     | 322W7JE       |
    | 10   | 23     | exit     | 0NTHK55       |
*/

.schema atm_transactions

SELECT account_number, transaction_type, amount
  FROM atm_transactions
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND atm_location = 'Leggett Street';

/*
Possible suspects:
    | account_number | transaction_type | amount |
    | 28500762       | withdraw         | 48     |
    | 28296815       | withdraw         | 20     |
    | 76054385       | withdraw         | 60     |
    | 49610011       | withdraw         | 50     |
    | 16153065       | withdraw         | 80     |
    | 25506511       | withdraw         | 20     |
    | 81061156       | withdraw         | 30     |
    | 26013199       | withdraw         | 35     |
*/

.schema phone_calls

SELECT caller, receiver
  FROM phone_calls
 WHERE day = 28
   AND month = 7
   AND year = 2021
   AND duration < 60;

/*
Possible suspects:
    |     caller     |    receiver    |
    | (130) 555-0289 | (996) 555-8899 |
    | (499) 555-9472 | (892) 555-8872 |
    | (367) 555-5533 | (375) 555-8161 |
    | (499) 555-9472 | (717) 555-1342 |
    | (286) 555-6063 | (676) 555-6554 |
    | (770) 555-1861 | (725) 555-3243 |
    | (031) 555-6622 | (910) 555-3251 |
    | (826) 555-1652 | (066) 555-9701 |
    | (338) 555-6650 | (704) 555-2131 |
*/

SELECT full_name, city
  FROM airports, flights
 WHERE airports.id = flights.destination_airport_id
   AND day = 29
   AND month = 7
   AND year = 2021
   AND origin_airport_id IN
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
 ORDER BY hour, minute
 LIMIT 1;

/*
Airport and city names the suspect escaped to:
    |     full_name     |     city      |
    | LaGuardia Airport | New York City |
*/

SELECT passport_number
  FROM passengers, flights
 WHERE passengers.flight_id = flights.id
   AND day = 29
   AND month = 7
   AND year = 2021
   AND origin_airport_id IN
       (SELECT id
          FROM airports
         WHERE city = 'Fiftyville')
 ORDER BY hour, minute
 LIMIT 1;
