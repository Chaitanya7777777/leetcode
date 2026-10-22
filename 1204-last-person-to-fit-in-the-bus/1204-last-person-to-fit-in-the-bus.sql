# Write your MySQL query statement below
select person_name
from (
    select * , sum(weight) over (order by turn) as totweight
    from queue
) q
where totweight<=1000
order by totweight desc
limit 1