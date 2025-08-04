# Write your MySQL query statement below
(SELECT name AS results
FROM(
    SELECT m.user_id, u.name, COUNT(m.user_id)
    FROM MovieRating m
    JOIN Users u ON m.user_id = u.user_id
    GROUP BY m.user_id
    ORDER BY COUNT(m.user_id) DESC, u.name
) t
LIMIT 1
)
UNION ALL

(SELECT title AS results
FROM(
    SELECT m.movie_id, mo.title, AVG(m.rating)
    FROM MovieRating m
    JOIN Movies mo ON m.movie_id = mo.movie_id
    WHERE m.created_at BETWEEN '2020-02-01' AND '2020-02-28'
    GROUP BY movie_id
    ORDER BY AVG(m.rating) DESC, mo.title ASC
) tt
LIMIT 1
);