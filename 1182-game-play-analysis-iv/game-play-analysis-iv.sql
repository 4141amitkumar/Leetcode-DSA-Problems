# Write your MySQL query statement below
WITH T AS(
    SELECT player_id, event_date, LEAD(event_date) OVER (PARTITION by player_id ORDER BY event_date) AS next_event_date, ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY event_date) AS rn
    FROM Activity
),
X AS (
    SELECT player_id as C
    FROM T
    WHERE rn = 1 AND DATEDIFF(next_event_date,event_date)=1
)
SELECT ROUND(COUNT(C)/(SELECT COUNT(DISTINCT player_id) FROM Activity),2) AS fraction
FROM X