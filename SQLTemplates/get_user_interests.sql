SELECT "UserInterest"."UserRate", "UserInterest".user_interest_id, "UserInterest".form_id, "UserInterest".interest_id, "Interest"."Name", "Interest"."Description" FROM chaihona."UserInterest" JOIN chaihona."Interest" using (interest_id) WHERE form_id = {}