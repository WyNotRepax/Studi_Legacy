SELECT count(*)as anzahl
FROM ismember
WHERE organization = 'NATO'
GROUP BY organization;