# Write your MySQL query statement below
select Name as Customers
from Customers
where ID not in (select Customers.ID
                  from Orders, Customers
                  where Orders.CustomerID = Customers.ID);