# Write your MySQL query statement below
select B.Id
from Weather as A join Weather as B
where TO_DAYS(A.RecordDate) + 1 = TO_DAYS(B.RecordDate) and A.Temperature < B.Temperature;