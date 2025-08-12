# Write your MySQL query statement below
WITH T AS(
    SELECT requester_id as user_id, accepter_id AS friend_id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id as user_id, requester_id AS friend_id
    FROM RequestAccepted
)
SELECT user_id AS id, COUNT(DISTINCT friend_id) AS num
FROM T
GROUP BY id
ORDER BY num DESC, user_id
LIMIT 1;