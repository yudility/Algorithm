SELECT ID, EMAIL, FIRST_NAME, LAST_NAME
FROM DEVELOPERS  
WHERE (SKILL_CODE & 256) > 0  -- Python
   OR (SKILL_CODE & 1024) > 0  -- C#
ORDER BY ID