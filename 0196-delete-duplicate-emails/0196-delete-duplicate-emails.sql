# Write your MySQL query statement below
Delete p1
From person p1
Join person p2
ON p1.email = p2.email
Where p1.id > p2.id;
