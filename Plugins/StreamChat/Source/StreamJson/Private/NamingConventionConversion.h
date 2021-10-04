#pragma once

namespace NamingConventionConversion
{
/** Given a UpperCamelCase name, convert it to snake_case */
FString ConvertNameToSnakeCase(const FStringView InName);

/** Given a UpperCamelCase property name, convert it to snake_case (may remove some superfluous parts of the property name) */
FString ConvertPropertyNameToSnakeCase(const FStringView InName);

/** Given an snake_case string, convert it to UpperCamelCase */
FString ConvertSnakeCaseToUpperCamelCase(const FStringView InString);
}	 // namespace NamingConventionConversion
