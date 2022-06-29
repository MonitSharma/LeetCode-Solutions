select t.Request_at as Day,
        cast(sum(case when Status <> 'completed' then 1.00 else 0.00 end)/count(*) as decimal(10,2)) as 'Cancellation Rate'
from Trips as t
join Users as uc on t.Client_Id = uc.Users_Id and uc.Banned = 'No'
join Users as ud on t.Driver_id = ud.Users_Id and ud.Banned = 'No'
where t.Request_at between '2013-10-01' and '2013-10-03'
group by t.Request_at