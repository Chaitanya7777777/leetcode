SELECT P.firstName,P.lastName,A.city,A.state
From Person AS P
left join Address AS A
ON P.personId=A.personId;