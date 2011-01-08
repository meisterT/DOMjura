#ifndef EVENT_H
#define EVENT_H

#include <QObject>
#include <QDateTime>

namespace DJ {
	namespace Model {
		enum EventType {
			UNKNOWN,
			JUDGINGEVENT,
			SUBMISSIONEVENT
		};

		class Event : public QObject {
			Q_OBJECT
		public:
			explicit Event(QString id, QDateTime datetime, QObject *parent = 0);
			virtual QString toString() = 0;
			virtual EventType getType();
			QString getId();

		protected:
			QString id;
			QDateTime datetime;
		};
	} // namespace Model
} // namespace DJ

#endif // EVENT_H