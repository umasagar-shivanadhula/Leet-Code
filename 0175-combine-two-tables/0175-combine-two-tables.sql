# Write your MySQL query statement below
select p.firstName,p.lastName,t.city,t.state from person p left join address t on p.personid=t.personid;