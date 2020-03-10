select Scores.Score, tmp.Rank
from
Scores
left join
(   ---下面是统计每个分数有多少分数比他高，也就是排名，得到tmp表
    select t.Score, count(t.Score)as Rank
    from (
        select a.Score as Score
        from
        (select distinct Score from Scores)as a,
        (select distinct Score from Scores)as b
        where
        a.Score <= b.Score
    )as t
    group by t.Score
)as tmp
on Scores.Score = tmp.Score
order by tmp.Rank asc;

# 或者以下
# 下面的语句要慢 原因是在子表中初始值太多

select s1.Score, count(distinct(s2.Score)) Rank
from Scores s1, Scores s2
where s1.Score <= s2.Score
group by s1.Id
order by Rank