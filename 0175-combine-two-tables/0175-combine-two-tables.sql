SELECT firstName,lastName,city,state
FROM Person left join Address
ON Person.PersonId=Address.PersonId;