# Write your MySQL query statement below
SELECT request_at AS Day, 
    ROUND(cancelled/total,2) AS 'Cancellation Rate'
FROM (
    SELECT t.request_at, 
           COUNT(*) AS total, 
           SUM(status='cancelled_by_driver' OR status='cancelled_by_client') AS cancelled
    FROM Trips t
    JOIN Users uc ON t.client_id = uc.users_id
    JOIN Users ud ON t.driver_id = ud.users_id
    WHERE uc.banned='No' 
      AND ud.banned='No'
      AND t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
    GROUP BY t.request_at
) tt
ORDER BY request_at;