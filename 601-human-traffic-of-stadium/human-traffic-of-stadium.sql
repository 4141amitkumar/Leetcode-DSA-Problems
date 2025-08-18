# Write your MySQL query statement below
SELECT  id, visit_date, people
FROM Stadium s1
WHERE people>=100
AND(
    EXISTS(
        SELECT 1
        FROM Stadium s2, Stadium s3
        WHERE s2.people>=100 AND s3.people>=100
        AND s3.id=s2.id+1
        AND s2.id=s1.id+1
    )
    OR
    EXISTS(
        SELECT 1
        FROM Stadium s2, Stadium s3
        WHERE s2.people>=100 AND s3.people>=100
        AND s3.id=s2.id-1
        AND s2.id=s1.id-1
    )
    OR
    EXISTS(
        SELECT 1
        FROM Stadium s2, Stadium s3
        WHERE s2.people>=100 AND s3.people>=100
        AND s3.id=s1.id+1
        AND s2.id=s1.id-1
    )
);