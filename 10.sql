SELECT DISTINCT(name), rating
  FROM people
  JOIN directors
    ON people.id = directors.person_id
  JOIN movies
    ON directors.person_id = movies.id
  JOIN ratings
    ON movies.id = ratings.movie_id
 WHERE rating >= 9;
