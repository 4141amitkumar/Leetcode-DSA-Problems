# Write your MySQL query statement below
WITH not_returned AS(
    SELECT lb.*, COUNT(br.book_id) AS current_borrowers
    FROM library_books lb
    JOIN borrowing_records br
    ON lb.book_id=br.book_id
    WHERE br.return_date IS NULL
    GROUP BY br.book_id
)
SELECT book_id, title, author, genre, publication_year, current_borrowers
FROM not_returned
WHERE total_copies=current_borrowers
ORDER BY current_borrowers DESC, title