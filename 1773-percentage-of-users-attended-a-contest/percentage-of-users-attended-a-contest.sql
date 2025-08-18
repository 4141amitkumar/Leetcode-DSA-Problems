# Write your MySQL query statement below
SELECT DISTINCT r.contest_id, ROUND((COUNT(r.contest_id)/(SELECT COUNT(user_id) FROM Users))*100,2) AS percentage
FROM Register r
JOIN Users u ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, contest_id;